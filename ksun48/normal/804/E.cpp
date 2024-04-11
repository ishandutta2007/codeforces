#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	if(n % 4 == 2 || n % 4 == 3){
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	if(n == 1) return 0;
	int a[n];
	for(int i = 0; i < n; i++) a[i] = i;
	if(n % 4 == 0){
		for(int i = 0; i < n; i++){
			int j = i;
			if(j % 4 == 2){
				j++;
			} else if(j % 4 == 3){
				j--;
			}
			for(int c = 0; c < n; c++){
				int d = (j - c + n) % n;
				if(c < d){
					swap(a[c],a[d]);
					printf("%d %d\n", c+1, d+1);
				}
			}
		}
	}
	if(n % 4 == 1){
		n--;
		for(int i = 0; i < n; i++){
			int j = i;
			if(j % 4 == 2){
				j++;
			} else if(j % 4 == 3){
				j--;
			}
			for(int c = 0; c < n; c++){
				int d = (j - c + n) % n;
				if(j == 1){
					if(c < d){
						swap(a[n],a[d]);
						swap(a[c],a[d]);
						swap(a[n],a[c]);
						printf("%d %d\n", d+1, n+1);
						printf("%d %d\n", c+1, d+1);
						printf("%d %d\n", c+1, n+1);
					}
					continue;
				}
				if(c < d){
					swap(a[c],a[d]);
					printf("%d %d\n", c+1, d+1);
				}
			}
		}
		n++;
	}
	/*for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << endl;*/

}