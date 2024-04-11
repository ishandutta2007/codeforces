#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int w1, b1;
  scanf("%d%d", &w1, &b1);
  //double dragon96[w1+1][b1+1];
  //double ktreins[w1+1][b1+1];
  double dragon96[2][b1+1];
  double ktreins[2][b1+1];
  for(int a = 0; a <= w1; a++){
    for(int c = 0; c <= b1; c++){
      for(int k = 0; k < 1; k++){
	double w = (double) a;
	double b = (double) c;
	if(c == 0){
	  if(DEBUG) printf("d %d %d 0\n", a, c);
	  dragon96[a%2][c] = 0;
	  break;
	}
	if(a == 0){
	  if(DEBUG) printf("d %d %d 1\n", a, c);
	  dragon96[a%2][c] =  0;
	  break;
	}
	if(a + c < 3){
	  dragon96[a%2][c] = 0;
	  break;
	}
	double g; 
	//if(DEBUG) after dragon picks a black, prob that princess wins
	if(b == 1){
	  g = 1;
	} else {
	  //printf("a= %d c= %d\n", a, c);
	  g = (w/(w+b-1))*ktreins[(2+a-1)%2][c-1] + ((b-1)/(w+b-1))*ktreins[a%2][c-2];
	}
	if(DEBUG) printf("d %d %d %.10f\n", a, c, ((b/(w+b))*g));
	dragon96[a%2][c] = ((b/(w+b))*g);
	break;
      }
      for(int k = 0; k < 1; k++){
	//if(DEBUG)// P(princess wins; dragon's turn; a white, c black)
	double w = (double) a;
	double b = (double) c;
	if(a == 0){
	  if(DEBUG) printf("p %d %d 0\n", a, c);
	  ktreins[a%2][c] = 0;
	  break;
	}
	if(c == 0){
	  if(DEBUG) printf("p %d %d 1\n", a, c);
	  ktreins[a%2][c] = 1;
	  break;
	}
	if(DEBUG) printf("p %d %d %.10f\n", a, c, (w/(w+b) + b/(w+b)*dragon96[a%2][c-1]));
	ktreins[a%2][c] = (w/(w+b) + (b/(w+b))*dragon96[a%2][c-1]);
	break;
      }
    }
  }
  printf("%.10f\n", ktreins[w1 % 2][b1]);
}

// g++ 148D.cpp; cat 148D.in | ./a.out 1