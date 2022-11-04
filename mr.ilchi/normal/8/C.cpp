/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>	

#define Pair pair <int,int>
#define X first
#define Y second

using namespace std;

const int MAXN= 24+3;
const int MAXL= (1<<24)+5;

bool mark[MAXN];
int n;
int dp[MAXL], Pow[MAXN];
Pair a[MAXN];

inline int dis (Pair &a1, Pair &a2){
	return (a1.X-a2.X)*(a1.X-a2.X) + (a1.Y-a2.Y)*(a1.Y-a2.Y);
}
/*************************************/
inline void setDyn (){
	for (int i=1;i< Pow[n];i ++){
		int p= 1;
		while (mark[p])
			mark[p++]= false;
		mark[p]= true;
		dp[i] = 2*dis(a[p],a[0]) + dp[i^Pow[p-1]];

		int cur= i^Pow[p-1];
		for (int j=p+1;j<= n;j ++)
			if (mark[j])
				dp[i]= min(dp[i], dp[cur^Pow[j-1]]+ dis(a[0],a[p]) + dis(a[p],a[j]) + dis(a[j],a[0]));
	}
}	
/***********************************/
inline void setPow (){
	Pow[0]= 1;
	for (int i= 1;i<= n;i ++)
		Pow[i]= Pow[i-1]*2;
}
/***********************************/
int main (){
	cin >> a[0].X >> a[0].Y;
	cin >> n;
	for (int i= 1;i<= n;i ++)
		cin >> a[i].X >> a[i].Y;

	setPow ();
	setDyn ();
	
	int tmp= Pow[n]-1;
	cout << dp[tmp] << endl;
	memset (mark, true, sizeof mark);
	while (tmp){
		int start= -1;
		for (int i= 1;i<= n;i ++){
			if (mark[i]){
				start= i;
				break;
			}
		}
		mark[start]= false;
		int k= tmp;
		tmp= tmp^Pow[start-1];
		if (dp[k]== dp[tmp]+ dis(a[start],a[0])*2){
			cout << "0 " << start << " ";
			continue;
		}
		for (int i=start+1;i<= n;i ++){
			if (mark[i]){
				if (dp[k]== (dp[tmp^Pow[i-1]]+ dis(a[0],a[start]) + dis(a[start],a[i]) + dis(a[i],a[0]))){
					cout << "0 " << start << " " << i << " ";
					mark[i]= false;
					tmp^= (Pow[i-1]);
					break;
				}
			}
		}
	}
	cout << "0\n";

	return 0;
}