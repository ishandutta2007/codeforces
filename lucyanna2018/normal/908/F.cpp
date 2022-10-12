#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int res;
vector<int> r,g,b;
int calc_first(int pos,const vector<int>&a){
	vector<int>::const_iterator it = lower_bound(a.begin(),a.end(),pos);
	if(it == a.begin())return 0;
	return pos - a[0];
}
int calc_last(int pos,const vector<int>&a){
	vector<int>::const_iterator it = lower_bound(a.begin(),a.end(),pos);
	if(it == a.end())return 0;
	return a.back() - pos;
}
int calc_mid(int pos1, int pos2, int cur, const vector<int>&a){
	vector<int>::const_iterator it = upper_bound(a.begin(), a.end(), cur);
	int res = 0;
	if(it != a.end() && *it <= pos2)
		res += pos2 - *it;
	if(it != a.begin()){
		--it;
		if(*it >= pos1)
			res += *it - pos1;
	}
	return res;
}
int calc_mid(int pos1, int pos2, int pos3){
	return calc_mid(pos1,pos2,pos3,r) + calc_mid(pos1,pos2,pos3,b);
}
int main(){
	int n,x;
	char s[9];
	for(scanf("%d",&n); n--;){
		scanf("%d%s",&x,s);
		if(*s=='R')r.push_back(x);else
		if(*s=='G')g.push_back(x);else
		if(*s=='B')b.push_back(x);
	}
	if(g.empty()){
		if(r.size() > 2)res += r.back() - r[0];
		if(b.size() > 2)res += b.back() - b[0];
	}else{
		res += calc_first(g[0], r);
		res += calc_first(g[0], b);
		res += calc_last(g.back(), r);
		res += calc_last(g.back(), b);
		for(int i=0; i+1<g.size(); i++){
			res += g[i+1] - g[i];
			int cur = g[i+1] - g[i];
			cur = min(cur, calc_mid(g[i], g[i+1], g[i]));
			for(vector<int>::iterator it = lower_bound(r.begin(), r.end(), g[i]); it != r.end() && *it < g[i+1]; it++){
				cur = min(cur, calc_mid(g[i], g[i+1], *it));
			}
			for(vector<int>::iterator it = lower_bound(b.begin(), b.end(), g[i]); it != b.end() && *it < g[i+1]; it++){
				cur = min(cur, calc_mid(g[i], g[i+1], *it));
			}
			res += cur;
		}
	}
	printf("%d\n",res);
	return 0;
}