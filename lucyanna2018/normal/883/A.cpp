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
int64 human_cnt, human_tim, door_tim, t[111111];
int m;

int64 get_human_id_next(int64 tim){
	int64 id = tim / human_tim;
	if(id * human_tim < tim)id++;
	return min(human_cnt + 1, id);
}
int64 simu(int64 cur, int64 to, int64&nex){
	if(cur > to)return 0;
	int64 nex_human_id = get_human_id_next(cur);
	int64 stop_human_id = get_human_id_next(to + 1) - 1;
	if(nex_human_id > stop_human_id)return 0;

	int64 batch_size = door_tim / human_tim + 1;
	int64 ret = (stop_human_id - nex_human_id + 1 - 1) / batch_size + 1;
	nex = (nex_human_id + batch_size * (ret - 1)) * human_tim + door_tim + 1;
	return ret;
}
int main(){
	scanf("%I64d%d%I64d%I64d",&human_cnt,&m,&human_tim,&door_tim);
	for(int i=0; i<m; i++)
		scanf("%I64d",&t[i]);
	sort(t,t+m);
	int64 res = 0, cur = 1;
	//cur denote the door closed time.
	for(int i=0; i<m; i++){
		res += simu(cur, t[i] - door_tim - 1, cur);
		if(cur > t[i])continue;

		int64 nex_human_id = get_human_id_next(cur);
		if(nex_human_id > human_cnt){
			cur = t[i] + door_tim + 1;
			res ++;
		}else{
			cur = min(nex_human_id * human_tim, t[i]) + door_tim + 1;
			res ++;
		}
	}
	res += simu(cur, human_cnt * human_tim, cur);
	printf("%I64d\n",res);
	return 0;
}