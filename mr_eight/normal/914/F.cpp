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
#define ll long long //long long
#define ms multiset
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
#define openf(a) freopen(#a".in","r",stdin);freopen(#a".out","w",stdout)
#define re register
#define ri re int
#define il inline
#define cp complex<double>
#define endl '\n'//
//#pragma GCC optimize(3)
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
}string s,s2;
bitset<200002>c[30],ans;
int q,t1,t2,t3,n,m;
char ch;
int main(){
    cin>>s>>q;
    n=s.size();
    s.insert(0,"#");
    F(i,1,n){
    	c[s[i]-'a'][i]=1;
	}
    while(q--){
    	t1=read();
    	if(t1==1){
    		t2=read();
    		ch=getchar();
    		c[s[t2]-'a'][t2]=0;
    		c[ch-'a'][t2]=1;
    		s[t2]=ch;
		}else{
			t2=read(),t3=read();
			cin>>s2;
			m=s2.size();
			ans.set();
			F(i,0,m-1){
				ans&=(c[s2[i]-'a']>>i);
			}int r=t3-s2.size()+2;
			cout<<(max((int)(ans>>t2).count()-(int)(ans>>r).count(),0))<<endl;
		}
	}
    return 0;
}
/*
ababababa
2
2 1 7 aba
1 5 c
*/