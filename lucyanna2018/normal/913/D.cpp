/*#### bits/stdc++.h */
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<map>
#include<set>
#include<vector>
#include<deque>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;
/*####*/

#define ran 202222
int n,T,res;
pair<pair<int,int>,int> a[ran];
priority_queue<pair<pair<int,int>,int> > q;int sum;
int main(){
	scanf("%d%d",&n,&T);
	for(int i=0; i<n; i++){
		scanf("%d%d",&a[i].first.second,&a[i].first.first);
		a[i].second = i;
	}
	sort(a,a+n);
	res = n;
	for(int run = 0; run < 2; run++){
		int pnt = 0;
		while(!q.empty())q.pop();
		sum = 0;
		for(int i=1; i<=res; i++){
			while(!q.empty() && -q.top().first.first < i){
				sum -= q.top().first.second;
				q.pop();
			}
			for(; pnt < n && q.size() < i; pnt++){
				if(a[pnt].first.second >= i){
					q.push(make_pair(make_pair(-a[pnt].first.second, a[pnt].first.first),a[pnt].second));
					sum += a[pnt].first.first;
				}
			}
			if(q.size() < i || sum > T){
				res = i-1;
				break;
			}
		}
	}
	printf("%d\n%d\n",res,res);
	while(!q.empty()){
		printf("%d",q.top().second+1);
		q.pop();
		if(!q.empty())printf(" ");
	}
	puts("");
	return 0;
}