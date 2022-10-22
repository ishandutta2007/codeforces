#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e4+10;
int t,u,v;
queue<int>q1,q2;
stack<int>s;
inline int lowbit(int k){return k&-k;}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&u,&v);
		while(q1.size())q1.pop();
		while(u)q1.push(lowbit(u)),u-=lowbit(u);
		while(q2.size())q2.pop();
		while(v)q2.push(lowbit(v)),v-=lowbit(v);
		while(s.size())s.pop();
		while(q1.size()&&q2.size()){
			if(q1.front()>q2.front()){
				if(s.size()&&s.top()<q2.front())s.pop();
				else break;
			}
			else if(q1.front()==q2.front())q1.pop();
			else{
				q1.pop();
				while(q1.size()>q2.size()-1&&q1.front()<q2.front())s.push(q1.front()),q1.pop();
			}
			q2.pop();
		}
		puts(q1.size()||q2.size()?"NO":"YES");
	}
	return 0;
}