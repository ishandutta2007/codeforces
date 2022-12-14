#include <cstdio>
#include <queue>
using namespace std;
const int MAXN = 200005;
typedef long long int LL;

struct Event{
	LL time, len, id;
	bool isNew;
	bool operator < (const Event &rhs) const{
		if(time != rhs.time) return time > rhs.time;
		return int(isNew) > int(rhs.isNew);
	}
};
priority_queue <Event> eventQueue;
queue <Event> queryQueue;
int n, b; LL ans[MAXN];

int main(){
	int i; Event tmp; bool isBusy = false;
	scanf("%d%d", &n, &b);
	tmp.isNew = true;
	for(i = 1; i <= n; ++ i){
		scanf("%I64d%I64d", &tmp.time, &tmp.len);
		tmp.id = i;
		eventQueue.push(tmp);
	}
	while(!eventQueue.empty()){
		tmp = eventQueue.top(); eventQueue.pop();
		if(tmp.isNew){
			if(isBusy){
				if(int(queryQueue.size()) < b) queryQueue.push(tmp);
				else ans[tmp.id] = -1;
			}else{
				tmp.time += tmp.len; tmp.isNew = false;
				eventQueue.push(tmp);
				isBusy = true;
			}
		}else{
			ans[tmp.id] = tmp.time;
			if(queryQueue.empty()){
				isBusy = false;
				continue;
			}
			tmp.time += queryQueue.front().len; tmp.isNew = false;
			tmp.id = queryQueue.front().id;
			queryQueue.pop();
			eventQueue.push(tmp);
			isBusy = true;
		}
	}
	for(i = 1; i <= n; ++ i) printf("%I64d%c", ans[i], i == n ? '\n' : ' ');
	return 0;
}