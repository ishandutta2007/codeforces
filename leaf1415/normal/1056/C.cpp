#include <iostream>
#include <utility>
#include <set>

using namespace std;
typedef pair<int, int> P;

int n, m;
int p[2005];
set<P> S;
bool used[2005];
int part[2005];
int t;

int main(void)
{
	cin >> n >> m;
	for(int i = 1; i <= 2*n; i++) cin >> p[i];
	int a, b;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		part[a] = b;
		part[b] = a;
		S.insert(make_pair(a, b));
	}
	cin >> t;
	
	int nx = -1;
	for(int j = 0; j < 2*n; j++){
		int out;
		if(t == 1){
			if(nx != -1){
				out = nx;
				nx = -1;
			}
			else if((int)S.size() > 0){
				P x = *S.begin();
				S.erase(S.begin());
				if(p[x.first] > p[x.second]) out = x.first;
				else out = x.second;
			}
			else{
				int mx = 0, mx_i;
				for(int i = 1; i <= 2*n; i++){
					if(used[i]) continue;
					if(p[i] > mx){
						mx = p[i];
						mx_i = i;
					}
				}
				out = mx_i;
			}
			cout << out << endl;
			used[out] = true;
		}
		else{
			int res;
			cin >> res;
			if(res == -1) return 0;
			used[res] = true;
			if(S.count(make_pair(res, part[res]))){
				nx = part[res];
				S.erase(make_pair(res, part[res]));
			}
			else if(S.count(make_pair(part[res], res))){
				nx = part[res];
				S.erase(make_pair(part[res], res));
			}
		}
		if(t == 1) t = 0;
		else t = 1;
	}
	return 0;
}