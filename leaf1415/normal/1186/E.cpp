#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#define llint long long
#define eps 1e-9

using namespace std;

llint h, w, Q;
llint a[2005][2005];
llint sum[2005][2005];

llint rect(llint sx, llint sy, llint tx, llint ty)
{
	if(sx > tx || sy > ty) return 0;
	return sum[tx][ty] - sum[sx-1][ty] - sum[tx][sy-1] + sum[sx-1][sy-1];
}

llint get(llint x, llint y)
{
	llint ret = 0;
	for(;x;x/=2) ret += x&1;
	for(;y;y/=2) ret += y&1;
	return ret%2;
}

llint calc(llint y, llint x)
{
	if(y <= 0 || x <= 0) return 0;
	//cout << "@" << x << " " << y << endl;
	llint X = x / w, Y = y / h;
	llint ret = (X/2*2) * (Y/2*2) / 2 * h * w;
	
	//cout << X << " " << Y << endl;
	llint remx = x % (2*w), remy = y % (2*h);// cout << remx << " " << remy << endl;cout << ret << endl;
	ret += rect(1, 1, remx, 2*h) * (Y/2); //cout << ret << endl;
	ret += rect(1, 1, 2*w, remy) * (X/2); //cout << ret << endl;
	
	if(get((x+2*w-1)/(2*w)-1, (y+2*h-1)/(2*h)-1) == 0) ret += rect(1, 1, remx, remy);
	else ret += remx*remy - rect(1, 1, remx, remy);
	
	//cout << ret << endl;
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> h >> w >> Q;
	char c;
	for(int i = 1; i <= h; i++){
		for(int j = 1; j <= w; j++){
			cin >> c;
			a[j][i] = c-'0';
		}
	}
	for(int y = 1; y <= 2*h; y++){
		for(int x = 1; x <= 2*w; x++){
			a[x][y] = a[(x-1)%w+1][(y-1)%h+1];
			if((x-1)/w + (y-1)/h == 1) a[x][y] = 1 - a[x][y];
		}
	}
	for(int y = 1; y <= 2*h; y++){
		for(int x = 1; x <= 2*w; x++){
			sum[x][y] = a[x][y] + sum[x-1][y] + sum[x][y-1] - sum[x-1][y-1];
		}
	}
	/*for(int y = 1; y <= 2*h; y++){
		for(int x = 1; x <= 2*w; x++){
			cout << a[x][y] << " ";
		}
		cout << endl;
	}*/
	
	
	llint sx, sy, tx, ty;
	for(int q = 0; q < Q; q++){
		cin >> sx >> sy >> tx >> ty;
		llint ans = calc(tx, ty); //cout << calc(tx, ty) << endl;;
		ans -= calc(sx-1, ty); //cout << calc(sx-1, ty) << endl;;
		ans -= calc(tx, sy-1); //cout << calc(tx, sy-1) << endl;;
		ans += calc(sx-1, sy-1); //cout << calc(sx-1, sy-1) << endl;;
		cout << ans << "\n"; //cout << endl;
	}
	
	return 0;
}