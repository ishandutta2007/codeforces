//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <climits>
#include <functional>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <complex>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define itn int
#define nit int
#define ll long long
#define ms multiset
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
#define openf(a) freopen(#a".in","r",stdin);freopen(#a".out","w",stdout)
#define re register
#define ri re int
#define il inline
#define pii pair<int,int>
#define cp complex<double>
//#pra gma G CC opti mize(3)
using namespace std;
using std::bitset;
//using namespace __gnu_pbds;
const double Pi=acos(-1);
inline int read() {
	int x=0;
	bool fu=0;
	char ch=0;
	while(ch>'9'||ch<'0') {
		ch=getchar();
		if(ch=='-')fu=1;
	}
	while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
	return fu?-x:x;
}
inline char readc(){
	register char c;
	while((c=getchar())==' '||c=='\n');
	return c;
}
ll t,n,m,a[102][102],ans=0,qwq[10];
int main(){
    cin>>t;
    while(t--){
    	cin>>n>>m;
    	F(i,1,n){
    		F(j,1,m){
    			a[i][j]=read();
			}
		}ans=0;
		if((n%2)&&(m%2)){
			F(i,1,n/2){
				F(j,1,m/2){
					qwq[1]=a[i][j];
					qwq[2]=a[n-i+1][m-j+1];
					qwq[3]=a[i][m-j+1];
					qwq[4]=a[n-i+1][j];
					sort(qwq+1,qwq+5);
					ans+=qwq[2]-qwq[1]+qwq[3]-qwq[2]+qwq[3]-qwq[2]+qwq[4]-qwq[3];
				}
			}F(i,1,n/2){
				ans+=labs(a[i][m/2+1]-a[n-i+1][m/2+1]);
			}F(i,1,m/2){
				ans+=labs(a[n/2+1][i]-a[n/2+1][m-i+1]);
			}cout<<ans<<'\n';
		}else if(n%2){
			F(i,1,n/2){
				F(j,1,m/2){
					qwq[1]=a[i][j];
					qwq[2]=a[n-i+1][m-j+1];
					qwq[3]=a[i][m-j+1];
					qwq[4]=a[n-i+1][j];
					sort(qwq+1,qwq+5);
					ans+=qwq[2]-qwq[1]+qwq[3]-qwq[2]+qwq[3]-qwq[2]+qwq[4]-qwq[3];
				}
			}F(i,1,m/2){
				ans+=labs(a[n/2+1][i]-a[n/2+1][m-i+1]);
			}cout<<ans<<'\n';
		}else if((m%2)){
			F(i,1,n/2){
				F(j,1,m/2){
					qwq[1]=a[i][j];
					qwq[2]=a[n-i+1][m-j+1];
					qwq[3]=a[i][m-j+1];
					qwq[4]=a[n-i+1][j];
					sort(qwq+1,qwq+5);
					ans+=qwq[2]-qwq[1]+qwq[3]-qwq[2]+qwq[3]-qwq[2]+qwq[4]-qwq[3];
				}
			}F(i,1,n/2){
				ans+=labs(a[i][m/2+1]-a[n-i+1][m/2+1]);
			}cout<<ans<<'\n';
		}else{
			F(i,1,n/2){
				F(j,1,m/2){
					qwq[1]=a[i][j];
					qwq[2]=a[n-i+1][m-j+1];
					qwq[3]=a[i][m-j+1];
					qwq[4]=a[n-i+1][j];
					sort(qwq+1,qwq+5);
					ans+=qwq[2]-qwq[1]+qwq[3]-qwq[2]+qwq[3]-qwq[2]+qwq[4]-qwq[3];
				}
			}cout<<ans<<'\n';
		}
	}
    return 0;
}