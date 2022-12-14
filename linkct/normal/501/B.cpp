#include <iostream>
#include <map>
#include <string>
using namespace std;
const int MAXN = 1005;
typedef pair <string, int> psi;

int cnt, q;
string str1, str2, now[MAXN], init[MAXN];
map <string, int> storage;

int main(){
	int i;
	cin >> q;
	for(i = 1; i <= q; ++ i){
		cin >> str1 >> str2;
		if(storage.find(str1) == storage.end()){//new user
			init[++ cnt] = str1;
			now[cnt] = str2;
			storage.insert(psi (str1, cnt));
			storage.insert(psi (str2, cnt));
		}else{
			now[storage[str1]] = str2;
			storage.insert(psi (str2, storage[str1]));
		}
	}
	cout << cnt << endl;
	for(i = 1; i <= cnt; ++ i)
		cout << init[i] << ' ' << now[i] << endl;
	return 0;
}