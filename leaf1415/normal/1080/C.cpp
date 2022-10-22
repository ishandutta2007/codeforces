#include <iostream>
#define llint long long

using namespace std;

struct rect{
	llint sx, sy, gx, gy;
	rect(){}
	rect(llint a, llint b, llint c, llint d){
		sx = a, sy = b, gx = c, gy = d;
	}
	llint size(){
		return (gx-sx+1) * (gy-sy+1);
	}
	llint count(){
		if(sx > gx || sy > gy) return 0;
		llint ret = size()/2;
		if(size()%2 && (sx+sy)%2) ret++;
		return ret;
	}
	rect intersect(rect obj){
		return rect(max(sx, obj.sx), max(sy, obj.sy), min(gx, obj.gx), min(gy, obj.gy));
	}
};

llint T;
llint h, w;
llint a, b, c, d;
rect white, black, inter;

int main(void)
{
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> h >> w;

		cin >> a >> b >> c >> d;
		white = rect(a, b, c, d);
		cin >> a >> b >> c >> d;
		black = rect(a, b, c, d);
		inter = white.intersect(black);
		
		llint ans = rect(1, 1, w, h).count();
		ans -= white.count() + black.count() - inter.count();
		ans += black.size();
		cout << w*h-ans << " " << ans << endl;
	}
	return 0;
}