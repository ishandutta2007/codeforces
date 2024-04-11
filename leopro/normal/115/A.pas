var
  N, i, counter, employee, max: LongInt;
  a: array [1..2000] of LongInt;

begin
  ReadLn(N);
  For i := 1 to N do ReadLn(a[i]);
  
  max := 0;
  For i := 1 to N do
  begin
    employee := i;
    counter := 0;
    While employee > -1 do
    begin
      employee := a[employee];
      inc(counter);
    end;
    If max < counter then max := counter; 
  end;
  WriteLn(max);
end.