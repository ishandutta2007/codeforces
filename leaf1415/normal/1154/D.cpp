#include <iostream>

using namespace std;

int n, b, a;
int A, B;
int s[200005];

int main(void)
{
	cin >> n >> B >> A;
	for(int i = 1; i <= n; i++) cin >> s[i];
	
	int ans = n, a = A, b = B;
	for(int i = 1; i <= n; i++){
		if(s[i] == 0){
			if(a > 0) a--;
			else if(b > 0) b--;
			else{
				ans = i-1;
				break;
			}
		}
		else{
			if(b > 0){
				if(a == A) a--;
				else b--, a++;
			}
			else if(a > 0) a--;
			else{
				ans = i-1;
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}