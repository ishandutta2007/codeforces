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

#define int64 long long int
//time, car_id, pos
priority_queue<pair<int64,pair<int,int> > > running_car;
#define ran 222222
int house, cars, q;
int wait_cnt;
priority_queue<pair<int64,int> > wait[ran];

int bit[ran];
int lowbit(int x){return x&-x;}
void upd(int x,int y){
	while(x <= house){
		bit[x] += y;
		x += lowbit(x);
	}
}
int query(int x){
	if(x <= 0)return 0;
	if(x > house) x = house;
	int res = 0;
	while(x){
		res += bit[x];
		x -= lowbit(x);
	}
	return res;
}
void process(int64 cur){
	while(!running_car.empty() && -running_car.top().first <= cur){
		int64 available_time = -running_car.top().first;
		int id = running_car.top().second.first;
		int pos = running_car.top().second.second;
		running_car.pop();
		wait_cnt++;
		wait[pos].push(make_pair(-available_time, -id));
		upd(pos, 1);
	}
}
pair<int64,int> get_id(int pos){
	if(pos <= 0 || pos > house || wait[pos].empty())return make_pair(-1,-1);
	return make_pair(-wait[pos].top().first, -wait[pos].top().second);
}
int main(){
	scanf("%d%d%d",&house,&cars,&q);
	for(int i=1; i<=cars; i++){
		int x;
		scanf("%d",&x);
		wait_cnt ++;
		wait[x].push(make_pair(0LL,-i));
		upd(x, 1);
	}
	int64 cur = 0;
	while(q--){
		int64 T;int from,to;
		scanf("%I64d%d%d",&T,&from,&to);
		if(cur < T){
			cur = T;
			process(cur);
		}
		if(wait_cnt == 0){
			cur = -running_car.top().first;
			process(cur);
		}
		int lo = 0, hi = house;
		while(lo != hi){
			int mi = (lo + hi)/2;
			if(query(from+mi) - query(from-mi-1) != 0)
				hi = mi;
			else
				lo = mi+1;
		}
		pair<int64,int> A = get_id(from + lo);
		pair<int64,int> B = get_id(from - lo);
		int id, pos;
		if(A.second != -1 && (B.second == -1 || A < B)){
			id = A.second;
			pos = from+lo;
		}
		else{
			id = B.second;
			pos = from-lo;
		}
		
		wait[pos].pop();
		wait_cnt --;
		upd(pos, -1);
		running_car.push(make_pair(-(cur+(long long int)labs(pos-from)+(long long int)labs(from-to)),make_pair(id,to)));
		printf("%d %I64d\n",id, cur - T + (long long int)labs(pos-from));
	}
	return 0;
}