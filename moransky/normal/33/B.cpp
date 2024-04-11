#include <iostream>
#include <string>
#include <math.h>
using namespace std;
const int inf = 0x3f3f3f3f;
char a,b;
string s1,s2,p="";
int w,n,g[27][27],ans=0,cnt=0;
int main() {
	cin >> s1 >> s2;
	if(s1.size()!=s2.size()){
		cout << -1;return 0;
	}
	cin >> n;
	for(int i=0;i<26;i++)
		for(int j=0;j<26;j++)
			if(i!=j)g[i][j]=inf;
	for(int i=1;i<=n;i++){
		cin >> a >> b >> w;
		g[a-'a'][b-'a']=min(w,g[a-'a'][b-'a']);
	}
	for(int k=0;k<26;k++)
		for(int i=0;i<26;i++)
			for(int j=0;j<26;j++)
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	for(int i=0;i<s1.size();i++){
		if(s1[i]==s2[i]){
			p+=s1[i];
			continue;
		}
		char r;int R=inf;
		for(int c=0;c<26;c++)
			if(g[s1[i]-'a'][c]+g[s2[i]-'a'][c]<R)
				R=g[s1[i]-'a'][c]+g[s2[i]-'a'][c],r=c+'a';
		if(R==inf){
			cout << -1;
			return 0;
		}
		p+=r;
		ans+=R;
	}
	cout << ans << endl << p;
}