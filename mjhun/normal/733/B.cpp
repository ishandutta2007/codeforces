#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int n,L,R,s0,s1;
int l[100005],r[100005];

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d%d",l+i,r+i),L+=l[i],R+=r[i];
	s0=abs(L-R);s1=0;
	fore(i,0,n){
		int ss=abs((L-l[i]+r[i])-(R-r[i]+l[i]));
		if(ss>s0){
			s0=ss;
			s1=i+1;
		}
	}
	printf("%d\n",s1);
	return 0;
}