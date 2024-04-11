#include <iostream>
#include <set>
#define llint long long

using namespace std;

llint n;

int main(void)
{
	cin >> n;
	
	llint ans = 0;
	for(int i = 0; i <= min(n, 8LL); i++){
		ans += n-i+1;
		//cout << ans << endl;
		if(i < 8)
		for(int j = 0; j <= min(n-(i+1), 4LL); j++){
			ans += max(n-(i+j+1)+1, 0LL);
		}
		//cout << ans <<endl;
	}
	
	
	/*set<int> s;
	for(int l = 0; l <= 10; l++){
		for(int i = 0; i <= 10; i++){
			for(int j = 0; j <= 10; j++){
				for(int k = 0; k <= 10; k++){
					if(i+j+k+l == 10){
						if(l > 0 && k >= 5) continue;
						if(j >= 9) continue;
						if(s.count((i*10+j*5+k+50*l))) cout << "*" << endl;
						s.insert(i*10+j*5+k+50*l);
						cout << l << " " << i << " " << j << " " << k << " " << i*10+j*5+k+50*l << endl;
					}
				}
			}
		}
	}
	cout << s.size() << endl;*/
	
	
	cout << ans << endl;
	return 0;
}