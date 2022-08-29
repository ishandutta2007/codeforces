#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<string>
#include<utility>
#include<iostream>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)


int num_item;
int sum_of_space;
string item_name[120], item_type[120]; int att[120], def[120], res[120], size[120];

int num_atr;
string atr_name[1200], atr_type[1200]; int bonus[1200]; string dummy[1200];

int get_max(int item_id, int used_list[] ,int *used_num){
  int i;
  int mx;
  int sz = 0;
  string nm;

  if(item_type[item_id] == "weapon") mx = att[item_id], nm = "gladiator";
  if(item_type[item_id] == "armor")  mx = def[item_id], nm = "sentry";
  if(item_type[item_id] == "orb")    mx = res[item_id], nm = "physician";

  rep(i,num_atr) if(atr_type[i]==nm){
    if(sz >= size[item_id]) break;
    mx += bonus[i];
    used_list[sz++] = i;
  }

  *used_num = sz;
  return mx;
}

int get_status(int item_id, int used_list[] ,int *used_num){
  int i;
  int mx;
  int sz = 0;
  string nm;

  if(item_type[item_id] == "weapon") mx = att[item_id], nm = "gladiator";
  if(item_type[item_id] == "armor")  mx = def[item_id], nm = "sentry";
  if(item_type[item_id] == "orb")    mx = res[item_id], nm = "physician";

  rep(i,num_atr) if(dummy[i] == item_name[item_id]){
    if(atr_type[i]==nm) mx += bonus[i];
    used_list[sz++] = i;
  }

  *used_num = sz;
  return mx;
}

int main(){
  int i,j,k,l,m,n;

  int used[1200];
  int used_list[1200], used_size;

  int res1, res2, res3;
  int res1_list[1200], res1_size;
  int res2_list[1200], res2_size;
  int res3_list[1200], res3_size;
  int mx, tmp;

  pair<string, pair<int, string> > for_sort[1200];

  while(scanf("%d",&num_item)==1){
    sum_of_space = 0;
    rep(i,num_item){
      cin >> item_name[i] >> item_type[i] >> att[i] >> def[i] >> res[i] >> size[i];
      sum_of_space += size[i];
    }

    scanf("%d",&num_atr);
    rep(i,num_atr){
      cin >> atr_name[i] >> atr_type[i] >> bonus[i] >> dummy[i];
    }

    if(sum_of_space == num_atr){
      mx = -1;
      rep(i,num_item) if(item_type[i] == "weapon"){
        tmp = get_status(i, used_list, &used_size);
        if(mx < tmp) mx = tmp, res1 = i;
      }
      mx = -1;
      rep(i,num_item) if(item_type[i] == "armor"){
        tmp = get_status(i, used_list, &used_size);
        if(mx < tmp) mx = tmp, res2 = i;
      }
      mx = -1;
      rep(i,num_item) if(item_type[i] == "orb"){
        tmp = get_status(i, used_list, &used_size);
        if(mx < tmp) mx = tmp, res3 = i;
      }

      get_status(res1, res1_list, &res1_size);
      get_status(res2, res2_list, &res2_size);
      get_status(res3, res3_list, &res3_size);
      
    } else {

      rep(i,num_atr) for_sort[i] = make_pair( atr_type[i], make_pair(-bonus[i], atr_name[i]) );
      sort(for_sort, for_sort+num_atr);
      rep(i,num_atr){
        atr_type[i] = for_sort[i].first;
        bonus[i] = -for_sort[i].second.first;
        atr_name[i] = for_sort[i].second.second;
      }

      rep(i,num_atr) used[i] = 0;

      mx = -1;
      rep(i,num_item) if(item_type[i] == "weapon"){
        tmp = get_max(i, used_list, &used_size);
        if(mx < tmp) res1 = i, mx = tmp;
      }
    
      mx = -1;
      rep(i,num_item) if(item_type[i] == "armor"){
        tmp = get_max(i, used_list, &used_size);
        if(mx < tmp) res2 = i, mx = tmp;
      }
    
      mx = -1;
      rep(i,num_item) if(item_type[i] == "orb"){
        tmp = get_max(i, used_list, &used_size);
        if(mx < tmp) res3 = i, mx = tmp;
      }

      get_max(res1, res1_list, &res1_size);
      get_max(res2, res2_list, &res2_size);
      get_max(res3, res3_list, &res3_size);
      rep(i,res1_size) used[res1_list[i]] = 1;
      rep(i,res2_size) used[res2_list[i]] = 1;
      rep(i,res3_size) used[res3_list[i]] = 1;

      rep(i,num_atr) if(!used[i]){
        if(size[res1] > res1_size){
          res1_list[res1_size++] = i;
          used[i] = 1;
          continue;
        }
        if(size[res2] > res2_size){
          res2_list[res2_size++] = i;
          used[i] = 1;
          continue;
        }
        if(size[res3] > res3_size){
          res3_list[res3_size++] = i;
          used[i] = 1;
          continue;
        }
      }
    }

    printf("%s %d",item_name[res1].c_str(), res1_size);
    rep(i,res1_size) printf(" %s",atr_name[res1_list[i]].c_str());
    puts("");
    printf("%s %d",item_name[res2].c_str(), res2_size);
    rep(i,res2_size) printf(" %s",atr_name[res2_list[i]].c_str());
    puts("");
    printf("%s %d",item_name[res3].c_str(), res3_size);
    rep(i,res3_size) printf(" %s",atr_name[res3_list[i]].c_str());
    puts("");
  }

  return 0;
}