#include <iostream>
#include <vector>
#define llint long long

using namespace std;

struct BIT{
	int size;
	vector<llint> bit;
	BIT(){size = 0;}
	BIT(int s){
		size = s;
		bit.resize(size+1);
		init();
	}
	void init(){
		for(int i = 1; i <= size; i++) bit[i] = 0;
	}
	llint query(int i){
		llint ret = 0;
		while(i > 0){
			ret += bit[i];
			i -= i&(-i);
		}
		return ret;
	}
	void add(int i, llint x){
		while(i <= size){
			bit[i] += x;
			i += i&(-i);
		}
	}
};


llint T;
llint m, n;
llint a[100005], b[100005], ainv[100005];
llint p[100005];
bool used[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 1; t <= T; t++){
		cin >> n >> m;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1; i <= n; i++) ainv[a[i]] = i;
		
		for(int i = 1; i <= n; i++) p[i] = 0;
		for(int i = 1; i <= m; i++) used[i] = false;
		
		for(int i = 1; i <= m; i++) cin >> b[i];
		for(int i = 1; i <= m; i++) p[ainv[b[i]]] = i;
		
		int id = m+1;
		for(int i = 1; i <= n; i++){
			if(p[i] == 0) p[i] = id++;
		}
		
		//for(int i = 1; i <= n; i++) cout << p[i] << " "; cout << endl;
		
		llint ans = 0, sorted = 0;
		for(int i = 1; i <= m; i++){
			if(used[i]) ans++;
			else{
				for(int j = sorted+1; j <= n; j++){
					used[p[j]] = true;
					if(p[j] == i){
						sorted = j;
						ans += 2*(j-i)+1;
						break;
					}
				}
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}