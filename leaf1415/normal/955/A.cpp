#include <iostream>
#include <stdio.h>

using namespace std;

int h, m;
int H, D, C, N;

int main(void)
{
	cin >> h >> m;
	int time = h * 60 + m;
	cin >> H >> D >> C >> N;
	
	double ans;
	if(time >= 1200){
		ans = (H + N - 1) / N * C * 0.8;
	}
	else{
		ans = (H + N - 1) / N * C;
		ans = min(ans, ((H+(1200-time)*D)+N-1)/N*C*0.8);
	}
	
	printf("%.8f\n", ans);
	return 0;
}