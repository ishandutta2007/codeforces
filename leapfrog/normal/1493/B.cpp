//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
const int rev[10]={0,1,5,10000,10000,2,10000,10000,8,10000};
int H,M,HH,MM,T;string S;
inline char chk(int h,int m)
{
	if(rev[h/10]==10000||rev[h%10]==10000||rev[m/10]==10000||rev[m%10]==10000) return 0;
	if(rev[m%10]*10+rev[m/10]>=H||rev[h%10]*10+rev[h/10]>=M) return 0;
	return 1;
}
inline void solve()
{
	read(H),read(M),cin>>S,HH=(S[0]-'0')*10+S[1]-'0',MM=(S[3]-'0')*10+S[4]-'0';
	while(!chk(HH,MM))
	{
		if(++MM==M) MM=0,HH++;
		if(HH==H) HH=0;
	}
	printf("%02d:%02d\n",HH,MM);
}
int main() {for(read(T);T--;) solve();return 0;}