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
bitset<1002>a[1002],b,c[1002],xx[1002],qwq;
int n,k,cnt[1002],tot;
bool ed[1002][1002];
bool vis[1002];
int main(){
    cin>>n;
    F(i,1,1000)xx[i][i]=1;
    F(i,1,n){
    	cin>>k;
    	F(j,1,k)a[i][read()]=1;
	}F(i,1,n){
		F(j,i+1,n){
			if((b=(a[i]&a[j])).count()==2){
				ed[b._Find_first()][b._Find_next(b._Find_first())]=1;
				ed[b._Find_next(b._Find_first())][b._Find_first()]=1;
			}
		}
	}F(i,1,n){
		F(j,1,n){
			if(ed[i][j]){
				vis[i]=1;
				cnt[i]++;
			}
		}if(vis[i])tot++,qwq[i]=1;
	}F(i,1,n){if(vis[i])
		F(j,1,n){
			if(ed[i][j]&&vis[j]){
				c[i][j]=1;
			}
		}
	}
	/*F(i,1,n){
		if(!vis[i]){
			ri pos=a[i]._Find_first();
			while(!vis[pos])pos=a[i]._Find_next(pos);
			ed[pos][i]=ed[i][pos]=1;
		}
	}F(i,1,n){
		F(j,i,n){
			if(ed[i][j]){
				cout<<i<<' '<<j<<endl;
			}
		}
	}*/
	if(tot<=1){
		F(i,1,n){
			if(vis[i]){
				F(j,1,n){
					if(j!=i)cout<<i<<' '<<j<<endl;
				}return 0;
			}
		}F(i,2,n)cout<<i<<' '<<1<<endl;
	}if(tot==2){
		int x, y,root;
		for (int i = 1; i <= n; i++)
			if (vis[i]) x = i;
		for (int i = n; i; i--)
			if (vis[i]) y = i;
		for (int i = 1; i <= n; i++){
			if(a[i].count()!=n){
				F(j,1,n){
					if(j==x)continue;
					if(a[i][j])cout<<x<<' '<<j<<endl;
					else cout<<y<<' '<<j<<endl;
				}return 0;
			}
		}
			
	
	}else{
		F(i,1,n){
			ri pos,mmin=INT_MAX;
			F(j,1,n){
				if(a[j][i]==1){
					if(a[j].count()<mmin){
						pos=j,mmin=a[j].count();
					}
				}
			}
			if(!vis[i]){
				F(j,1,n){if(vis[j])
					if((a[pos]&qwq)==(c[j]|xx[j])){
						cout<<i<<' '<<j<<endl;break;
					}
				}
			}
		}
	}F(i,1,n){
		F(j,i,n){
			if(ed[i][j]){
				cout<<i<<' '<<j<<endl;
			}
		}
	}
    return 0;
}
/*
7
4 1 2 4 5
4 1 2 4 5
5 1 2 3 4 5
7 1 2 3 4 5 6 7
5 1 2 3 6 7
4 1 3 6 7
4 1 3 6 7
*/