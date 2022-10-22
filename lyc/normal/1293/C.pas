var n,q,i,r,c,r1,c1,ans,r2,c2,r3,c3:longint;b:array[0..2,0..100002]of 0..1;
begin
  readln(n,q);
  for i:=1 to q do
  begin
    readln(r,c);
    if r=2 then begin r1:=1;c1:=c+1;r2:=1;c2:=c;r3:=1;c3:=c-1;end
      else begin r1:=2;c1:=c-1;r2:=2;c2:=c;r3:=2;c3:=c+1;end;
    if (b[r,c]=1)and(b[r1,c1]=1) then dec(ans);
    if (b[r,c]=1)and(b[r2,c2]=1) then dec(ans);
    if (b[r,c]=1)and(b[r3,c3]=1) then dec(ans);
    b[r,c]:=1-b[r,c];
    if (b[r,c]=1)and(b[r1,c1]=1) then inc(ans);
    if (b[r,c]=1)and(b[r2,c2]=1) then inc(ans);
    if (b[r,c]=1)and(b[r3,c3]=1) then inc(ans);
    if (ans=0)and(b[2,n]=0)and(b[1,1]=0) then writeln('Yes') else writeln('No');
  end;
end.