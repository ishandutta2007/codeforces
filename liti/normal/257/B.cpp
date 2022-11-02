#include <iostream>
using namespace std;

int main()
{
	int n[2];
	int r1=0,r2=0,r11=0,r22=0;
	cin >> n[0] >> n[1];
	int s = n[0] + n[1];
	int l = 0;
	int num = n[0];
	//if ( n[1] < n[0] )
	//	l = 1;
	if ( n[0] == 0 )
		l = 1;
	if (n[l] == 0)
		cout << "0 0" << endl;
	n[l]--;
	//cout << l ;
	for(int i = 1;i < s;i++){
		if ( i % 2 == 0 )
		{
			if ( n[l] > 0 ){
				n[l]--;
				r1++;
			} else {
				n[ l * (-1) + 1]--;
				l = l*(-1) + 1;
				r2++;
			}
		}
		else{
			if ( n[ l * (-1) + 1 ] > 0 ){
				n[ l * (-1) + 1]--;
				r2++;
				l = l*(-1) + 1;
			}else{
				n[l]--;
				r1++;
			}
		}
	//cout << l ;
	}
	//cout << endl;
	
	n[0] = num;
	n[1] = s - num;
	l = 1;
	n[l]--;
	//cout << l ;
	for(int i = 1;i < s;i++){
		if ( i % 2 == 0 )
		{
			if ( n[l] > 0 ){
				n[l]--;
				r11++;
			} else {
				n[ l * (-1) + 1]--;
				l = l*(-1) + 1;
				r22++;
			}
		}
		else{
			if ( n[ l * (-1) + 1 ] > 0 ){
				n[ l * (-1) + 1]--;
				r22++;
				l = l*(-1) + 1;
			}else{
				n[l]--;
				r11++;
			}
		}
	//cout << l ;
	}
	//cout << endl;
	if ( r1 > r11 )
		cout << r1  << " " << r2 << endl;
	else
		cout << r11 << " " << r22 << endl;
}