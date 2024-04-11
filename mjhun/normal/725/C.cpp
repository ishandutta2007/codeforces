#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

char s[32];
char b[2][16];
int q[256];
char c;
int i0,i1;


int main(){
	scanf("%s",s);
	for(int i=0;s[i];++i)q[s[i]]++;
	for(int i=0;;++i)if(q[i]==2){c=i;break;}
	for(i0=0;s[i0]!=c;++i0);
	for(i1=i0+1;s[i1]!=c;++i1);
	if(i0+1==i1){puts("Impossible");return 0;}
	int k=(i1-i0-1)/2;
	b[0][k]=c;
	int is,js;
	if(k==0)is=1,js=0;
	else is=0,js=k-1;
	for(int i=is,j=js,t=(i0+1)%27;i!=0||j!=k;t=(t+1)%27){
		if(t==i1)t=(t+1)%27;
		b[i][j]=s[t];
		if(i==0&&j==0)i++;
		else if(i==1&&j==12)i--;
		else if(i==0)j--;
		else j++;
	}
	puts(b[0]);puts(b[1]);
	return 0;
}