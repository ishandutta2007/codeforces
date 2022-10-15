
var
  n, i, n0, n1, n2, min, max, ans: Int32;
  value: array [1..100000] of Int32;   

procedure WriteArray(a: array of LongInt; N: LongInt);
begin
  For i := 0 to N-1 do Write(a[i], ' ');
  WriteLn;
end;     

procedure Change(var a, b: Int32);
var
  tmp: Int32;
begin
  tmp := a;
  a := b;
  b := tmp;
end;

begin
  ReadLn(n);
  ans := n;
  For i := 1 to n do Read(value[i]);
  ReadLn;
  min := 100000;
  For i := 1 to n do If value[i] < min then min := value[i];
  max := -100000;
  For i := 1 to n do If value[i] > max then max := value[i];
  If max - min = 2 then
  begin
    n0 := 0;
    n1 := 0;
    n2 := 0;
    For i := 1 to n do
    begin
      If value[i] = min then inc(n0);
      If value[i] = min+1 then inc(n1);
      If value[i] = max then inc(n2);
    end;
    If n0 > n2 then Change(n0, n2);
    If n0 > n1 div 2 then
    begin
      ans := n-n0*2;
      n2 := n0;
      For i := 1 to n do
      begin
        If (value[i] = min) and (n0 > 0) then
        begin
          inc(value[i]);
          dec(n0);
        end;
        If (value[i] = max) and (n2 > 0) then
        begin
          dec(value[i]);
          dec(n2);
        end;
      end;
    end else
    begin
      n1 := n1 - (n1 mod 2);
      ans := n-n1;
      For i := 1 to n do
      begin
        If (value[i] = min+1) and (n1 mod 2 = 1) then
        begin
          inc(value[i]);
          dec(n1);
        end;
        If (value[i] = min+1) and (n1 > 0) and (n1 mod 2 = 0) then
        begin
          dec(value[i]);
          dec(n1);
        end;
      end;
    end;
  end;
  WriteLn(ans);
  WriteArray(value, n); 
end.