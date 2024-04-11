#include <iostream>

using namespace std;

int h;
int a[200005];
int parent[200005];

int main(void)
{
	cin >> h;
	for(int i = 0; i <= h; i++) cin >> a[i];
	
	int v = 1;
	int ans = 0, p[2];
	for(int i = 0; i <= h; i++){
		if(ans < 2){
			if(a[i] >= 2){
				p[ans] = v;
				ans++;
			}
			else ans = 0;
		}
		for(int j = 1; j <= a[i]; j++){
			parent[v] = v - j;
			v++;
		}
	}
	
	if(ans < 2) cout << "perfect" << endl;
	else{
		cout << "ambiguous" << endl;
		for(int i = 1; i <= v-1; i++){
			cout << parent[i];
			if(i < v-1) cout << " ";
		}
		cout << endl;
		parent[p[1]] = p[0];
		for(int i = 1; i <= v-1; i++){
			cout << parent[i];
			if(i < v-1) cout << " ";
		}
		cout << endl;
	}
	return 0;
}