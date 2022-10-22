#include <iostream>

using namespace std;

int n;

int searchX(int l, int r, int d, int u)
{
	int ub = r, lb = l-1, mid, res;
	while(ub-lb>1){
		mid=(ub+lb)/2;
		cout << "? "<< l << " " << d << " " << mid << " " << u << endl;
		cin >> res;
		if(res%2) ub = mid;
		else lb = mid;
	}
	return ub;
}

int searchY(int d, int u, int l, int r)
{
	int ub = u, lb = d-1, mid, res;
	while(ub-lb>1){
		mid=(ub+lb)/2;
		cout << "? "<< l << " " << d << " " << r << " " << mid << endl;
		cin >> res;
		if(res%2) ub = mid;
		else lb = mid;
	}
	return ub;
}

int main(void)
{
	cin >> n;
	int lbd = -1, ubd = -1, res;
	for(int i = 1; i < n; i++){
		cout << "? "<< 1 << " " << 1 << " " << i << " " << n << endl;
		cin >> res;
		if(res % 2){
			lbd = i;
			break;
		}
	}
	for(int i = 1; i < n-1; i++){
		cout << "? "<< 1 << " " << 1 << " " << n << " " << i << endl;
		cin >> res;
		if(res % 2){
			ubd = i;
			break;
		}
	}
	if(lbd == -1 && ubd == -1) ubd = n-1;
	
	int x1, y1, x2, y2;
	if(lbd != -1 && ubd == -1){
		y1 = y2 = searchY(1, n, 1, lbd);
		x1 = lbd, x2 = searchX(lbd+1, n, 1, n);
	}
	else if(ubd != -1 && lbd == -1){
		x1 = x2 = searchX(1, n, 1, ubd);
		y1 = ubd, y2 = searchY(ubd+1, n, 1, n);
	}
	else{
		cout << "? "<< lbd << " " << ubd << " " << lbd << " " << ubd << endl;
		cin >> res;
		if(res % 2){
			x1 = lbd, y1 = ubd;
			x2 = searchX(lbd+1, n, ubd+1, n), y2 = searchY(ubd+1, n, lbd+1, n);
		}
		else{
			x1 = lbd, y2 = ubd;
			x2 = searchX(lbd+1, n, 1, ubd), y1 = searchY(ubd+1, n, 1, lbd);
		}
	}
	cout << "! " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
	
	return 0;
}