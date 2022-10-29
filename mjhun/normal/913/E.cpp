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

bool ls(string s, string t){return t==""||SZ(s)<SZ(t)||SZ(s)==SZ(t)&&s<t;}

string r[256][2];bool c;

void doit(string s, int i , int k){if(ls(s,r[i][k]))r[i][k]=s,c=true;}

int main(){
	r[0xF][0]=r[0xF][1]="x";r[255^0xF][0]=r[255^0xF][1]="!x";
	r[0x33][0]=r[0x33][1]="y";r[255^0x33][0]=r[255^0x33][1]="!y";
	r[0x55][0]=r[0x55][1]="z";r[255^0x55][0]=r[255^0x55][1]="!z";
	c=true;
	while(c){
		c=false;
		fore(i,0,256){
			fore(k,0,2)if(SZ(r[i][k])){
				string s="!("+r[i][k]+")";
				doit(s,255^i,0);doit(s,255^i,1);
			}
		}
		fore(i,0,256)fore(j,0,256)fore(ki,0,2)fore(kj,0,2)if(SZ(r[i][ki])&&SZ(r[j][kj])){
			string s;
			if(!ki)s=r[i][ki];
			else s="("+r[i][ki]+")";
			s+="&";
			if(!kj)s+=r[j][kj];
			else s+="("+r[j][kj]+")";
			doit(s,i&j,0);
			s=r[i][ki];
			s+="|";
			s+=r[j][kj];
			doit(s,i|j,1);
		}
	}
	fore(i,0,256)if(ls(r[i][1],r[i][0]))r[i][0]=r[i][1];
	int n;
	scanf("%d",&n);
	while(n--){
		char s[16];
		scanf("%s",s);
		int x=0;
		fore(i,0,8)x=2*x+s[i]-'0';
		printf("%s\n",r[x][0].c_str());
	}
	return 0;
}