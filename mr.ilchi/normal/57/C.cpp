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
#include <cmath>
#include <vector>
#include <cstdio>

using namespace std;

const int MAXN= 100*1000+5;
const long long BASE= 1000000007;

bool mark[2*MAXN];
int n;
int cnt[2*MAXN];
vector <int> p;

inline void setP (){
	for (int i= 2,leni= 2*n-1;i<= leni;i ++)
		if (!mark[i]){
			p.push_back (i);
			int tmp= (i<<1);
			while (tmp<= leni){
				mark[tmp]= true;
				tmp+= i;
			}
		}

	p.push_back (BASE);
}	
/*********************************/
inline void change (int v, int key){
	for (int i= 0;p[i]<= v;i ++){
		long long tmp= p[i];
		while (tmp<= v){
			cnt[p[i]]+= (v/tmp)*key;
			tmp*= p[i];
		}
	}
}
/*********************************/
inline int Pow (int base, int len){
	long long r= 1;
	long long cur= base;
	while (len){
		if (len & 1)
			r= (r*cur)%BASE;
		len= (len>>1);
		cur= (cur*cur)%BASE;
	}
	return r;
}
/*********************************/
int main (){
	cin >> n;
	setP ();
	change (2*n-1, 1);
	change (n, -1);
	change (n-1,-1);

	long long res= 1;
	for (int i= 2, leni= 2*n;i<= leni;i ++)
		res= (res* Pow(i,cnt[i]))%BASE;

	res= ((res<<1)-n)%BASE;
	cout << res << endl;
		
	return 0;
}