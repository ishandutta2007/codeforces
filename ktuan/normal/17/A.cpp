#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fi first
#define se second
#define pb push_back
#define MP make_pair

typedef pair<int,int> PII;
typedef vector<int> VI;

bool p[1010];
bool ok[1010];
int main() {
	memset(p,true,sizeof(p));
	p[0]=p[1]=false;
	Rep(i,1010)if(p[i]){
		for(int j=i+i;j<1010;j+=i)p[j]=false;	
	}
	Rep(i,1010)if(p[i]){
		For(j,i+1,1009)if(p[j]){
			if(i+j<=1000) ok[i+j]=true;
			break;	
		}	
	}
	int n,k;
	cin>>n>>k;
	int r=0;
	For(i,2,n)if(ok[i-1]&&p[i])++r;//, cout<<i<<endl;;
	if(r>=k)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;	
}