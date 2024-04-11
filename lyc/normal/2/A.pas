var n,i,t,max,j:longint;bl:boolean;st:ansistring;nm,a:array[0..10000]of ansistring;b,b1,k:array[0..10000]of longint;
begin
  max:=-maxlongint;
  readln(n);
  for i:=1 to n do
  begin
    readln(st);bl:=true;
    nm[i]:=copy(st,1,pos(' ',st)-1);
    delete(st,1,pos(' ',st));
    val(st,k[i]);
    for j:=1 to t do
      if a[j]=nm[i] then
      begin
        bl:=false;
        inc(b[j],k[i]);
        break;
      end;
    if bl then
    begin
      inc(t);
      a[t]:=nm[i];
      inc(b[t],k[i]);
    end;
  end;
  for i:=1 to t do
  begin
    if b[i]>max then max:=b[i];
  end;
  for i:=1 to n do
  begin
    for j:=1 to t do
      if a[j]=nm[i] then
      begin
        inc(b1[j],k[i]);
        if (b1[j]>=max)and(b[j]=max) then
        begin
          writeln(a[j]);
          halt;
        end;
      end;
  end;
end.