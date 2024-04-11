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
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

typedef long long ll;
typedef pair<int,int> Pair;

const int maxL= 100+5;
const int maxN= 50+5;

int n;
vector <int> prime;

struct Bint{
	int len;
	int dig[maxL];

	Bint(){
		len=1;
		memset (dig, 0, sizeof dig);
		dig[0]=1;
	}

	inline void operator *= (const int &v){
		for (int i=0;i<len;i++)
			dig[i]*= v;

		for (int i=0;i<maxL-1;i++){
			dig[i+1]+= dig[i]/10;
			dig[i]%=10;
		}

		for (int i=maxL-1;i>=0;i--) if(dig[i]){
			len= i+1;
			return;
		}
	}

	inline void print(){
		for (int i=len-1;i>=0;i--)
			cout << dig[i];
		cout << endl;
	}

}a[maxN];
/**********************************/
inline void Set(int id){
	int i= id%n;
	for (int j=1;j<n;j++){
		a[id]*= prime[i];
		i= (i+1)%n;
	}
}
/********************************/
int main(){	
	cin >> n;
	if (n==2){
		cout << -1 << endl;
		return 0;
	}
	
	for (int i=2; (int)prime.size()<n; i++){
		bool flag= false;
		for (int j=2;j*j<=i;j++)
			if((i%j)==0){
				flag= true;
				break;
			}
		if (!flag)
			prime.push_back (i);
	}

	for (int i=1;i<=n;i++)
		Set(i);

	for (int i=1;i<=n;i++)
		a[i].print();

	return 0;
}