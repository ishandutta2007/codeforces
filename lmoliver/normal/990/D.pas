var n,a,b,c,q,i,j:longint;aa:array[1..1000,1..1000]of longint;
begin
  read(n,a,b);
  if(a>1)and(b>1)then begin writeln('NO');exit;end;
  if((n=2)or(n=3))and(a=1)and(b=1)then begin writeln('NO');exit;end;
  writeln('YES');
  if a>1 then c:=1
  else c:=2;
  if c=1 then q:=n-a+1 else q:=n-b+1;
  for i:=1 to q-1 do begin aa[i,i+1]:=1;aa[i+1,i]:=1;end;
  if c=2 then
    for i:=1 to n do
      for j:=1 to n do
        if i<>j then aa[i,j]:=1-aa[i,j];
  for i:=1 to n do
  begin
    for j:=1 to n do write(aa[i,j]);
    writeln;
  end;
end.