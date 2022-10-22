#include <iostream>
#include <string>
#include <vector>

using namespace std;

int h, w;
char mat[300005], mat2[300005], ans[300005], ans2[300005];
int H, W;
bool flag1, flag2;
char c[] = {'A', 'G', 'C', 'T'};

int calc(char mat[], vector<char> ch[])
{
	int ret = 0;
	for(int i = 0; i < h; i++){
		int cnt = 0, tmp;
		for(int j = 0; j < w; j++) if(ch[i%2][j%2] != mat[i*w+j]) cnt++;
		tmp = cnt;
		
		cnt = 0;
		for(int j = 0; j < w; j++) if(ch[i%2][(j+1)%2] != mat[i*w+j]) cnt++;
		tmp = min(tmp, cnt);
		ret += tmp;
	}
	return ret;
}

void make(char mat[], vector<char> ch[])
{
	if(flag1) flag2 = true;
	for(int i = 0; i < h; i++){
		int cnt = 0, tmp;
		for(int j = 0; j < w; j++){
			if(ch[i%2][j%2] != mat[i*w+j]) cnt++;
			ans[i*w+j] = ch[i%2][j%2];
		}
		tmp = cnt;
		
		cnt = 0;
		for(int j = 0; j < w; j++) if(ch[i%2][(j+1)%2] != mat[i*w+j]) cnt++;
		if(tmp > cnt){
			for(int j = 0; j < w; j++) ans[i*w+j] = ch[i%2][(j+1)%2];
		}
	}
}

int solve(char mat[], int ret)
{
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(i >= j) continue;
			
			vector<char> ch[2];
			ch[0].push_back(c[i]), ch[0].push_back(c[j]);
			for(int k = 0; k < 4; k++){
				if(k != i && k != j) ch[1].push_back(c[k]);
			}
			
			int res = calc(mat, ch);
			if(res < ret){
				ret = res;
				make(mat, ch);
			}
		}
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> h >> w;
	for(int i = 0; i < h*w; i++){
		cin >> mat[i];
	}
	
	int ans_v = solve(mat, 1e9);
	swap(h, w);
	flag1 = true;
	for(int x = 0; x < w; x++){
		for(int y = 0; y < h; y++){
			mat2[y*w+x] = mat[x*h+y];
		}
	}
	solve(mat2, ans_v);
	
	swap(h, w);
	if(flag2){
		for(int x = 0; x < w; x++){
			for(int y = 0; y < h; y++){
				ans2[y*w+x] = ans[x*h+y];
			}
		}
	}
	
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			if(!flag2) cout << ans[i*w+j];
			else cout << ans2[i*w+j];
		}
		cout << endl;
	}
	
	return 0;
}