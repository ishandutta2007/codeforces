#include<bits/stdc++.h>
using namespace std;
stack<pair<char,int> > st;
long long a[100005];
int b[100005];
long long dp[100005];
int ct[100005];
char s[100005];
int n;
int main()
{
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;i++) {
		ct[i+1]=ct[i];
		if(s[i]=='[') ct[i+1]++;
		if(s[i]=='(' || s[i]=='[') {
			st.push(make_pair(s[i],i));
			b[i]=-1;
		}
		else {
			if(s[i]==')') {
				if(st.size()>0 && st.top().first=='(') {
					b[i]=st.top().second;
					if(b[i]>0 && b[b[i]-1]!=-1) b[i]=b[b[i]-1];
					st.pop();
				}
				else {
					b[i]=-1;
					while(st.size()>0) st.pop();
				}
			}
			else {
				if(st.size()>0 && st.top().first=='[') {
					b[i]=st.top().second;
					if(b[i]>0 && b[b[i]-1]!=-1) b[i]=b[b[i]-1];
					st.pop();
				}
				else {
					b[i]=-1;
					while(st.size()>0) st.pop();
				}
			}
		}
	}
	while(st.size()>0) st.pop();
	int r=-1;
	for(int i=0;i<n;i++) {
		if(b[i]!=-1 && (r==-1 || ct[r+1]-ct[b[r]]<ct[i+1]-ct[b[i]])) r=i;
	}
	if(r==-1) {
		printf("0\n");
		return 0;
	}
	printf("%d\n",ct[r+1]-ct[b[r]]);
	for(int i=b[r];i<=r;i++) printf("%c",s[i]);
	return 0;
}