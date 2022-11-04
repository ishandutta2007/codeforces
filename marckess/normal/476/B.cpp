#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void pascal(int tri[][15]){
	for(int i = 0; i < 12; i++){
		tri[i][0] = 1;
		for(int j = 1; j < i; j++)
			tri[i][j] = tri[i-1][j-1] + tri[i-1][j];
		tri[i][i] = 1;
	}
}

int main(){
	string s1,s2;
	int c1[2]={0}, c2[3]={0};

	cin >> s1 >> s2;

	for ( int i = 0; i < s1.size(); i++ ){
		if ( s1[i] == '+' )
			c1[0]++;
		else
			c1[1]++;

		if( s2[i] == '+' )
			c2[0]++;
		else if (s2[i] == '-')
			c2[1]++;
		else
			c2[2]++;
	}

	if ( c2[0] > c1[0] || c2[1] > c1[1] )
		cout << fixed << setprecision(10) << 0.0;
	else{
		int tri[15][15];
		pascal(tri);

		int h = c2[2];
		int dif0 = c1[0] - c2[0];
		int dif1 = c1[1] - c2[1];

		cout << fixed << setprecision(10)
		     << (double)tri[h][min(dif0, dif1)] / pow(2,h);
	}

	return 0;
}