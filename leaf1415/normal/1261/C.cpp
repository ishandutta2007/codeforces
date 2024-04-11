#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#define llint long long
#define POS(x, y) ((y)*(w)+(x))

using namespace std;
typedef pair<llint, llint> P;

llint h, w;
int a[3000005], s[3000005];
bool ans[3000005];

llint get(llint sx, llint sy, llint tx, llint ty){
	return s[POS(tx,ty)] - s[POS(sx-1,ty)] - s[POS(tx,sy-1)] + s[POS(sx-1,sy-1)];
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> h >> w;
	char c;
	for(int y = 1; y <= h; y++){
		for(int x = 1; x <= w; x++){
			cin >> c;
			if(c == 'X') a[POS(x, y)] = 1;
		}
	}
	for(int y = 1; y <= h; y++){
		for(int x = 1; x <= w; x++){
			s[POS(x, y)] = s[POS(x-1, y)] + s[POS(x, y-1)] - s[POS(x-1, y-1)] + a[POS(x, y)];
		}
	}
	
	llint mn = h+w+1;
	for(int y = 1; y <= h; y++){
		llint cnt = 0;
		for(int x = 1; x <= w; x++){
			if(a[POS(x, y)]) cnt++;
			else{
				if(cnt > 0) mn = min(mn, cnt);
				cnt = 0;
			}
		}
		if(cnt > 0) mn = min(mn, cnt);
	}
	for(int x = 1; x <= w; x++){
		llint cnt = 0;
		for(int y = 1; y <= h; y++){
			if(a[POS(x, y)]) cnt++;
			else{
				if(cnt > 0) mn = min(mn, cnt);
				cnt = 0;
			}
		}
		if(cnt > 0) mn = min(mn, cnt);
	}
	mn = (mn-1)/2;
	
	cout << mn << endl;
	for(int y = 1; y <= h; y++){
		for(int x = 1; x <= w; x++){
			if(x - mn < 1 || x + mn > w || y - mn < 1 || y + mn > h) continue;
			if(get(x-mn, y-mn, x+mn, y+mn) != (2*mn+1)*(2*mn+1)) continue;
			ans[POS(x, y)] = true;
		}
	}
	
	for(int y = 1; y <= h; y++){
		for(int x = 1; x <= w; x++){
			if(ans[POS(x, y)]) cout << "X";
			else cout << ".";
		}
		cout << endl;
	}
	
	return 0;
}