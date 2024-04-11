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
template<class T>
inline T read(T &x) {
	x=0;
	bool fu=0;
	char ch=0;
	while(ch>'9'||ch<'0') {
		ch=getchar();
		if(ch=='-')fu=1;
	}
	while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
	if(fu)x=-x;
}
inline int read(){
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
int h,n,t1,t2,t3,temp[1000002];
int t[1000002];
inline bool cmp(int x,int y){
	return t[x]>t[y];
}
int main(){
	srand(time(0));
    cin>>h;
    n=(1<<h)-1;
    F(i,1,420){
    	t1=rand()%n+1;
    	while((t2=rand()%n+1)==t1);
    	while((t3=rand()%n+1)==t1||t3==t2);
    	printf("? %d %d %d\n",t1,t2,t3);
    	fflush(stdout);
    	cin>>t1;
    	t[t1]++;
	}F(i,1,n)temp[i]=i;
	sort(temp+1,temp+n+1,cmp);
	F(i,3,n){
		printf("? %d %d %d\n",temp[1],temp[2],temp[i]);
		fflush(stdout);
		cin>>t1;
		if(t1==temp[i]){
			cout<<'!'<<' '<<temp[i]<<endl;
			return 0;
		}
	}
    return 0;
}