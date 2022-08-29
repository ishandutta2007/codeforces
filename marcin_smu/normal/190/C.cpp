#include<cstdio>
int n;
struct typ{
 int cz;
 typ *a,*b;
 typ(){};
};
char z[7];
bool xxx=0;
typ* q(){
     
 if((~scanf("%s",z))==0){
  xxx=1;
  z[0]='i';
 }

 if(z[0]=='i'){
  typ *pom2=new typ;
  pom2->cz=1;
  return pom2;
 }else{
  typ *pom2=new typ;
  pom2->cz=0;
  pom2->a=q();
  pom2->b=q();
  return pom2;
 }
}
void pr(typ* c){
 if(c->cz==1)
 printf("int");
 else{
  printf("pair<");
  pr(c->a);
  printf(",");
  pr(c->b);
  printf(">");
 }
}
main(){
 scanf("%d",&n);
 typ* pom=q();
 if(xxx||(~scanf("%s",z))){
  printf("Error occurred\n");
  return 0;
 }
 pr(pom);
 printf("\n");
}