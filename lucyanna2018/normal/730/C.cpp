#include<stdio.h>
#include<vector>
#include<string.h>
#include<utility>
#include<map>
using namespace std;
vector<int> e[5555];
vector<pair<int,int> > shop[5555];
int n;
map<int,int> Map;
int dis[5555];
int q[5555],op,cl;
void bfs(int city,int num,long long int val){
	for(int i=1; i<=n; i++)
		dis[i] = -1;
	dis[city] = 0;
	op=cl=0;
	q[op++] = city;
	long long int totalval = 0, totalnum = 0;
	Map.clear();
	while(op!=cl){
		int x = q[cl++];
		for(vector<pair<int,int> >::iterator it = shop[x].begin(); it != shop[x].end(); it++){
			int price = it->first, amount = it->second;
			totalnum += amount;
			totalval += ((long long int)price) * amount;
			Map[price] += amount;
			while(totalnum > num){
				map<int,int>::reverse_iterator iii = Map.rbegin();
				if(totalnum - iii ->second >= num){
					totalnum -= iii -> second;
					totalval -= ((long long int)iii->first) * iii->second;
					Map.erase(iii->first);
				}else{
					int dif = (int)(totalnum - num);
					totalnum -= dif;
					totalval -= ((long long int)iii->first) * dif;
					Map[iii->first] -= dif;
					break;
				}
			}

			if(totalnum == num && totalval <= val){
				printf("%d\n",dis[x]);
				return;
			}
		}
		for(vector<int>::iterator it = e[x].begin(); it!=e[x].end(); it++){
			int y=*it;
			if(dis[y] == -1){
				dis[y] = dis[x] + 1;
				q[op++] = y;
			}
		}
	}
	puts("-1");
}
int main(){
	int m,x,y,z;
	scanf("%d%d",&n,&m);
	while(m--){
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for(scanf("%d",&m); m--;){
		scanf("%d%d%d",&x,&y,&z);
		shop[x].push_back(make_pair(z,y));
	}
	for(scanf("%d",&m); m--;){
		scanf("%d%d%d",&x,&y,&z);
		bfs(x,y,z);
	}
	return 0;
}