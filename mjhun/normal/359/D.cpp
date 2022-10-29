#include <bits/stdc++.h>
using namespace std;

stack<int> st;
int a[300005],l[300005],r[300005],w[300005];
int n;
vector<int> sol;

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i)scanf("%d",a+i);
	for(int i=0;i<n;++i){
		while(!st.empty()&&a[st.top()]%a[i]==0)st.pop();
		l[i]=st.empty()?0:st.top()+1;
		st.push(i);
	}
	while(!st.empty())st.pop();
	for(int i=n-1;i>=0;--i){
		while(!st.empty()&&a[st.top()]%a[i]==0)st.pop();
		r[i]=st.empty()?n:st.top();
		st.push(i);
	}
	for(int i=0;i<n;++i)w[l[i]]=max(w[l[i]],r[i]-l[i]);
	int q=0;
	for(int i=0;i<n;++i)q=max(q,w[i]);
	for(int i=0;i<n;++i)if(w[i]==q)sol.push_back(i);
	printf("%d %d\n%d",(int)sol.size(),q-1,sol[0]+1);
	for(int i=1;i<sol.size();++i)printf(" %d",sol[i]+1);
	puts("");
	return 0;
}