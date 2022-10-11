var i,j,n,i1,i2,j1,j2:longint;
    A:array[1..50,1..50] of longint;
    chk: boolean;
    ch:char;
begin
readln(n);
for i:=1 to n do
  begin
    for j:=1 to n do
    begin
      read(ch);
      val(ch,A[i,j]);
    end;
    readln;
  end;
for i:=1 to n do
    if i1 = 0 then
    for j:=1 to n do if A[i,j] = 1 then
    begin
      i1:=i;
      j1:=j;
      break;
    end;
for i:=n downto 1 do
    if i2 = 0 then
    for j:=n downto 1 do if A[i,j]=1 then
    begin
      i2:=i;
      j2:=j;
      break;
    end;
for i:=j1+1 to j2-1 do
 begin
 if A[i1,i]<>2 then chk := True;
 if A[i2,i]<>2 then chk := True;
 end;
for i:=i1+1 to i2-1 do
 begin
 if A[i,j1]<>2 then chk := True;
 if A[i,j2]<>2 then chk := True;
 end;
if (A[i1,j2]<>1) or (A[i2,j1]<>1) then chk := True;
for i:=i1+1 to i2-1 do
 for j:=j1+1 to j2-1 do
 if A[i,j]<>4 then chk := True;
for i:=1 to n do
 for j:=1 to n do
 if A[i,j]>0 then
 if (not(i in [i1..i2])) or (not(j in [j1..j2])) then chk := True;
 if chk then write('No') else write('Yes');
end.