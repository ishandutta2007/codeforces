#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <vector>
#include <string.h>
int DEBUG = 0;
struct NODE{
  char name[11];
  int numpeople;
  int origid;
  int heights;
  void set(char *name_, int numpeople_, int origid_) {
    memcpy(name, name_, 11);
    numpeople = numpeople_;
    origid = origid_;
    heights = 0;
  }
  void print() {
    printf("name= <%s> numpeople= %d origid= %d heights= %d\n", name, numpeople, origid, heights);
  }
};
int compare_NODE_inc (const void * a, const void * b) {
  return ( (*(NODE*)a).numpeople - (*(NODE*)b).numpeople );
}
int compare_NODE_id (const void * a, const void * b) {
  return ( (*(NODE*)a).origid - (*(NODE*)b).origid);
}
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  
  int a;
  scanf("%d", &a);
  NODE people[a];
  char str[11];
  int numpeople;
  for(int i = 0; i < a; i++){
    scanf("%s%d", str, &numpeople);
    people[i].set(str, numpeople, 0);
  }
  qsort(people, a, sizeof(NODE), compare_NODE_inc);
  for(int i = 0; i < a; i++){
    //if(DEBUG) people[i].print();
  }
  for(int i = 0; i < a; i++){
    if(people[i].numpeople > i){
       printf("-1\n");
       exit(0);
    }  
    people[i].origid = i;
    //printf("%d\n\n\n", 12312);
    int taller = people[i].numpeople;
    NODE ithnode;
    ithnode.set(people[i].name, people[i].numpeople, i);
    for(int j = i-1; j >= taller; j--){
      assert( (j+1) < a );
      people[j+1].set(people[j].name, people[j].numpeople, people[j].origid);
    }
    people[taller].set(ithnode.name, ithnode.numpeople, ithnode.origid);
  }
  for(int i = 0; i < a; i++){
    people[i].heights = a-i;
  }
  qsort(people, a, sizeof(NODE), compare_NODE_id);
  for(int i = 0; i < a; i++){
    printf("%s %d\n", people[i].name, people[i].heights);
  }
}

// g++ -g 141C.cpp; cat 141C.in|./a.out 141C.in 1