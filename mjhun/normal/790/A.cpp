#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

string r[64];
bool w[64];
int n,k;

string t;

string nw(){
	int k=0;
	while(t[k]=='Z'||t[k]=='z')k++;
	t[k]++;
	return t;
}

int main(){
	t="Aaaaaaaaaa";
	scanf("%d%d",&n,&k);
	fore(i,0,n-k+1){
		char s[5];
		scanf("%s",s);
		w[i]=s[0]=='Y';
	}
	fore(i,0,k-1){
		r[i]=nw();
	}
	fore(i,0,n-k+1){
		if(w[i])r[i+k-1]=nw();
		else r[i+k-1]=r[i];
	}
	fore(i,0,n)printf("%s\n",r[i].c_str());
	return 0;
}