#include <iostream>

using namespace std;

int s, t;
int s2, t2, s3, t3;

int main(void)
{
	cin >> s >> t;
	
	while(s % 2 == 0) s2++, s /= 2;
	while(t % 2 == 0) t2++, t /= 2;
	while(s % 3 == 0) s3++, s /= 3;
	while(t % 3 == 0) t3++, t /= 3;
	
	if(s != t || s2 > t2 || s3 > t3){
		cout << -1 << endl;
		return 0;
	}
	cout << t2-s2 + t3-s3 << endl;
	return 0;
}