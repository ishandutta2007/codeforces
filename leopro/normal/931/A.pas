var
  a, b, c: Int32;
  
begin
  ReadLn(a, b);
  a := abs(a-b);
  b := a div 2;
  c := round((b+1)*(b/2));
  If a mod 2 = 1 then b := b+1 else b := 0;
  WriteLn(c+b+c);
end.