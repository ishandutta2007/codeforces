#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+9;

int x = 0;
int n;
int y = 1;
void up() {
	y++;
	cout << (char)(x+'a') << y << " ";
}
void down() {
	y--;
	cout << (char)(x+'a') << y << " ";
}
void left() {
	x--;
	cout << (char)(x+'a') << y << " ";
}
void right() {
	x++;
	cout << (char)(x+'a') << y << " ";
}
void hardRight() {
	x=7;
	cout << (char)(x+'a') << y << " ";
}
int main() {
	ios_base::sync_with_stdio(0);
	cin>>n;
	cout <<"a1 ";
	if(n == 15) {
		//huj
		for(int i = 0; i < 7; i++) {
			up();
		}
		for(int i = 0; i < 5; i++) {
			right();
		}
		down();
		hardRight();
		cout<<"h8\n";
		return 0;
	}
	int kon = 0;
	int kier = 1;
	for(int i = 0; i < 100; i++) {
		if(kon == 1) {
			cout <<"h8\n";
			return 0;
		}
		if(n == 2 && (x==7 || y==8)) {
			// cout <<"hiue\n";
			n++;
			kon = 1;
		}
		if(n == 2) {
			// cout<<"wioedfj";
			hardRight();
			cout << "h8" << endl;
			return 0;
		}
		if(i < 7) up();
		else if(i < 13) right();
		else if(i < 55) {
			if(i % 6 == 1) down(), kier *= -1;
			else if(kier == -1) left();
			else right();
		}
		else if(i == 55) hardRight();
		else up();
		n--;
	}
}