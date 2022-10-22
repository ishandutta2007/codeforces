var t,i1,n,ans,ma,mn,i:longint;b,b1,tong,a,x,y:array[0..400000]of longint;
begin
  read(t);
  for i1:=1 to t do
  begin
    read(n);ans:=0;
    for i:=1 to n do
    begin
      read(a[i]);
      b[i]:=0;
      b1[i]:=0;
      tong[i]:=0;
    end;
    ma:=-maxlongint;
    for i:=1 to n-1 do
    begin
      if a[i]>ma then ma:=a[i];
      if tong[a[i]]<>0 then break;
      tong[a[i]]:=1;
      if i=ma then b[i]:=1;
    end;
    ma:=-maxlongint;
    for i:=1 to n do tong[i]:=0;
    for i:=n downto 2 do
    begin
      if a[i]>ma then ma:=a[i];
      if tong[a[i]]<>0 then break;
      tong[a[i]]:=1;
      if n-i+1=ma then b1[i]:=1;
    end;
    ans:=0;
    for i:=1 to n-1 do
    begin
      //writeln('///',b[i],' ',b1[i+1]);
      if (b[i]=1)and(b1[i+1]=1) then
      begin
        inc(ans);
        x[ans]:=i;y[ans]:=n-i;
      end;
    end;
    writeln(ans);
    for i:=1 to ans do writeln(x[i],' ',y[i]);
  end;
end.