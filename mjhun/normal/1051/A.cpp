#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

char t[128];int n;
char s[128];
int q[3];

int main(){
	int tn;
	scanf("%d",&tn);
	while(tn--){
		scanf("%s",t);n=strlen(t);
		memcpy(s,t,sizeof(s));
		q[0]=q[1]=q[2]=0;
		fore(i,0,n){
			if(s[i]>='a'&&s[i]<='z')s[i]=0;
			else if(s[i]>='A'&&s[i]<='Z')s[i]=1;
			else s[i]=2;
			q[s[i]]++;
		}
		if(q[0]==n)t[0]='A',t[1]='0';
		else if(q[1]==n)t[0]='a',t[1]='0';
		else if(q[2]==n)t[0]='a',t[1]='A';
		else if(!q[0]){
			fore(i,0,n)if(q[s[i]]>1){t[i]='a';break;}
		}
		else if(!q[1]){
			fore(i,0,n)if(q[s[i]]>1){t[i]='A';break;}
		}
		else if(!q[2]){
			fore(i,0,n)if(q[s[i]]>1){t[i]='0';break;}
		}
		puts(t);
	}
	return 0;
}