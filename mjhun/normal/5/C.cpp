#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

char s[1<<20];
vector<int> w;
stack<int> t;
int n;

int main(){
	scanf("%s",s);n=strlen(s);
	int k=-1;
	fore(i,0,n){
		if(s[i]=='('){
			if(k>=0)t.push(k);
			else t.push(i);
			k=-1;
		}
		else {
			if(t.empty())k=-1;
			else k=t.top(),w.pb(i-t.top()+1),t.pop();
		}
	}
	if(w.empty()){puts("0 1");return 0;}
	sort(w.begin(),w.end());
	int r0=w.back(),r1=0;
	for(int i=w.size()-1;i>=0&&w[i]==r0;--i)r1++;
	printf("%d %d\n",r0,r1);
	return 0;
}