var a:array[0..1000]of longint;c,n,i,j,min,ans:longint;
begin
  read(n);
  for i:=1 to n do
  begin
    read(c);
    if a[c]=0 then inc(ans);
    a[c]:=i;
  end;
  writeln(ans);
  for i:=1 to 1000 do
  begin
    min:=0;
    for j:=1 to 1000 do
      if((min=0)or(a[j]<a[min]))and(a[j]<>0)then min:=j;
    if min<>0 then write(min,' ');
    a[min]:=0;
  end;
end.