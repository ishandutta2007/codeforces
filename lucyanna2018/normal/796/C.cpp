#include<bits/stdc++.h>
using namespace std;
#define ran 333333
int n;
int val[ran];
vector<int> e[ran];
multiset<int> s;
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&val[i]);
		s.insert(val[i]);
	}
	for(int i=1; i<n; i++){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	int bes = 1111111111;
	for(int i=1; i<=n; i++){
		int now = val[i];
		s.erase(s.find(val[i]));
		for(vector<int>::iterator it = e[i].begin(); it!=e[i].end(); it++){
			int y = *it;
			now = max(now, val[y]+1);
			s.erase(s.find(val[y]));
		}
		if(!s.empty())now = max(now, *s.rbegin()+2);
		s.insert(val[i]);
		for(vector<int>::iterator it = e[i].begin(); it!=e[i].end(); it++){
			int y = *it;
			s.insert(val[y]);
		}
		if(now < bes)bes = now;
	}
	printf("%d\n",bes);
	return 0;
}