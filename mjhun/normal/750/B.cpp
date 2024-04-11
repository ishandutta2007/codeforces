#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define M 20000
using namespace std;
typedef long long ll;

void perdi(){puts("NO");exit(0);}

int n;

int main(){
	scanf("%d",&n);
	int p=M;
	while(n--){
		char t[16];
		int x;
		scanf("%d%s",&x,t);
		if(p==M&&t[0]!='S')perdi();
		if(p==0&&t[0]!='N')perdi();
		if(t[0]=='S')p-=x;
		else if(t[0]=='N')p+=x;
		if(p<0||p>M)perdi();
	}
	if(p!=M)perdi();
	puts("YES");
	return 0;
}