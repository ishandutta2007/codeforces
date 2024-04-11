<?php

for(;;){
  $input = fgets(STDIN,4096);
  if($input === false) break;

  list($n, $x, $y) = explode(" ",$input);
  $y = trim($y);

  if( bccomp($n,$y) === 1 ){
    echo "-1\n";
    continue;
  }

  $mul = bcadd(bcadd($y, "-$n", 0), "1", 0);
  $sum = bcadd($n, "-1", 0);
  $sum = bcadd($sum, bcmul($mul, $mul, 0), 0);

  if( bccomp($sum,$x) === -1){
    echo "-1\n";
    continue;
  }

  echo $mul."\n";
  for($i=1;bccomp("$i",$n,0)===-1;$i++) echo "1\n";
}

?>