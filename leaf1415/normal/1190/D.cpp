#include <iostream>
#include <algorithm>
#include <utility>
#include <algorithm>
#include <vector>

#define llint long long

using namespace std;
typedef pair<llint, llint> P;

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

llint n;
llint x[200005], y[200005];
bool used[200005];
vector<llint> compX, compY;
vector<P> vec;
BIT bit(200005);
llint const W = 200003;

void comp(llint x[], vector<llint> &comp)
{
  for(int i = 1; i <= n; i++) comp.push_back(x[i]);
  sort(comp.begin(), comp.end());
  comp.erase(unique(comp.begin(), comp.end()), comp.end());
  for(int i = 1; i <= n; i++) x[i] = lower_bound(comp.begin(), comp.end(), x[i]) - comp.begin() + 1;
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];
  comp(x, compX), comp(y, compY);

  for(int i = 1; i <= n; i++) vec.push_back(make_pair(-y[i], x[i]));
  sort(vec.begin(), vec.end());


  llint ans = 0;
  llint nexty = vec[0].first, p = 0;
  vector<llint> tmp;
  while(1){
    tmp.clear();
    tmp.push_back(0);
    while(p < vec.size() && vec[p].first == nexty){
      llint x = vec[p].second;
      tmp.push_back(x);
      if(!used[x]){
        bit.add(x, 1);
        used[x] = true;
      }
      p++;
    }
    tmp.push_back(W);

    llint kind = bit.query(W);
    ans += kind*(kind+1)/2;

    for(int i = 1; i < tmp.size(); i++){
      llint kind = bit.query(tmp[i]-1) - bit.query(tmp[i-1]);
      ans -= kind*(kind+1)/2;
    }
    if(p < vec.size()) nexty = vec[p].first;
    else break;

    //for(int i = 0; i <= 5; i++) cout << used[i] << " "; cout << endl;
    //cout << ans << endl;
  }
  cout << ans << endl;

  return 0;
}