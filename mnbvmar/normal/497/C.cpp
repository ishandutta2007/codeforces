#include <bits/stdc++.h>

using namespace std;

typedef long long LL;


const int MaxN = 100005,
          MaxM = 100005;

struct singer {
	int minx, maxx, allow, id;
	bool operator<(const singer& other) const {
		if(maxx != other.maxx) return maxx < other.maxx;
		return minx < other.minx;
	}
};

struct note {
	int minx, maxx, id;
	bool operator<(const note& other) const {
		if(maxx != other.maxx) return maxx < other.maxx;
		return minx < other.minx;
	}
};

struct action {
	int where, id;
	bool isSinger, isBegin;

	action(){}
	action(int wher, int i, bool isSinge, bool isBegi)
		: where(wher), id(i), isSinger(isSinge), isBegin(isBegi) {}

	bool operator<(const action& other) const {
		if(where != other.where) return where < other.where;
		if(isBegin != other.isBegin)
			return isBegin;
		return !isSinger;
	}
};

int N, M;
note notes[MaxN];
singer singers[MaxM];

//set<note> availableNotes;


void input(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		notes[i] = note{a,b,i};
	}

	scanf("%d", &M);
	for(int i = 0; i < M; i++){
		int c, d, k;
		scanf("%d%d%d", &c, &d, &k);
		singers[i] = singer{c,d,k,i};
	}
}

int result[MaxN];
action actions[(MaxN+MaxM)*2];
set<pair<int,int>> people;


int main(){
	input();
//	sort(singers.begin(), singers.end());

/*	for(int i = 0; i < N; i++)
		availableNotes.insert(notes[i]);*/

	fill(result, result+N, -1);

	int ptr = 0;
	for(int i = 0; i < N; i++){
//		i = i;
		actions[ptr++] = action(notes[i].minx, i, false, false);
//		actions[ptr++] = action{note[i].maxx, i, false, false};
	}

	for(int i = 0; i < M; i++){
		actions[ptr++] = action(singers[i].minx, i, true, true);
		actions[ptr++] = action(singers[i].maxx, i, true, false);
	}

	sort(actions, actions+ptr);

	for(int act = 0; act < ptr; act++){
		int id = actions[act].id;
//		printf("%d %d %d %d\n", actions[act].where, actions[act].id, actions[act].isSinger,
//				actions[act].isBegin);
		if(actions[act].isSinger){

			if(actions[act].isBegin){
				people.insert(make_pair(singers[id].maxx, id));
			} else {
				people.erase(make_pair(singers[id].maxx, id));
			}
		} else {
			int whereend = notes[id].maxx;
			auto winner = people.lower_bound(make_pair(whereend, -1));
			if(winner == people.end()){
				printf("NO\n");
				return 0;
			}
			int idperson = winner->second;

			result[id] = idperson+1;

			if(singers[idperson].allow == 1){
				people.erase(make_pair(singers[idperson].maxx, idperson));
			} else {
				singers[idperson].allow--;
			}
		}
	}

	for(int i = 0; i < N; i++){
		if(result[i] == -1){
			printf("NO\n");
			return 0;
		}
	}

	printf("YES\n");
	for(int i = 0; i < N; i++)
		printf("%d ", result[i]);
	printf("\n");
}