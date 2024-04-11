#include <iostream>

using namespace std;

int n, k;
int p[100005];
int key[300];

int main(void)
{
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> p[i];
	for(int i = 0; i <= 255; i++) key[i] = -1;
	
	for(int i = 0; i < n; i++){
		if(key[p[i]] != -1) cout << key[p[i]] << " ";
		else{
			int j;
			for(j = p[i]; j > p[i]-k && j >= 0; j--){
				if(key[j] != -1) break;
			}
			if(j >= 0 && key[j] != -1 && p[i] - k < key[j]){
				for(int x = j; x <= p[i]; x++) key[x] = key[j];
			}
			else{
				j++;
				for(int x = j; x <= p[i]; x++) key[x] = j;
			}
			cout << key[p[i]] << " ";
		}
	}
	cout << endl;
	return 0;
}