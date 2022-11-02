#include <stdio.h>
#include <algorithm>

bool qwe(int b,int c){
	if(b>c) return true;
	else return false;
}

char c;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	#endif
	int s,i;
	bool m[26];
	scanf("%c",&c);
	for(i=0;i<26;i++) m[i]=false;
	while(c!='}'){
		if(c!='a'){
			if(c!='b'){
				if(c!='c'){
					if(c!='d'){
						if(c!='e'){
							if(c!='f'){
								if(c!='g'){
									if(c!='h'){
										if(c!='i'){
											if(c!='j'){
												if(c!='k'){
													if(c!='l'){
														if(c!='m'){
															if(c!='n'){
																if(c!='o'){
																	if(c!='p'){
																		if(c!='q'){
																			if(c!='r'){
																				if(c!='s'){
																					if(c!='t'){
																						if(c!='u'){
																							if(c!='v'){
																								if(c!='w'){
																									if(c!='x'){
																										if(c!='y'){
																											if(c!='z'){
																											}
																											else m[25]=true;
																										}
																										else m[24]=true;
																									}
																									else m[23]=true;
																								}
																								else m[22]=true;
																							}
																							else m[21]=true;
																						}
																						else m[20]=true;
																					}
																					else m[19]=true;
																				}
																				else m[18]=true;
																			}
																			else m[17]=true;
																		}
																		else m[16]=true;
																	}
																	else m[15]=true;
																}
																else m[14]=true;
															}
															else m[13]=true;
														}
														else m[12]=true;
													}
													else m[11]=true;
												}
												else m[10]=true;
											}
											else m[9]=true;
										}
										else m[8]=true;
									}
									else m[7]=true;
								}
								else m[6]=true;
							}
							else m[5]=true;
						}
						else m[4]=true;
					}
					else m[3]=true;
				}
				else m[2]=true;
			}
			else m[1]=true;
		}
		else m[0]=true;
		scanf("%c",&c);
	}
	s=0;
	for(i=0;i<26;i++){
		if(m[i]) s=s+1;
	}
	printf("%d",s);
}